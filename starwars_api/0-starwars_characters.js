#!/usr/bin/node

const request = require('request');

const filmId = process.argv[2];
if (!filmId) {
  console.error('Usage: ./0-starwars_characters.js <Film ID>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Failed to fetch film. Status code: ${response.statusCode}`);
    return;
  }

  const data = JSON.parse(body);

  if (!data.characters) {
    console.error('Invalid film ID or no characters found.');
    return;
  }

  const characterUrls = data.characters;

  const fetchCharacterName = (index) => {
    if (index >= characterUrls.length) {
      return;
    }

    request(characterUrls[index], (charError, charResponse, charBody) => {
      if (charError) {
        console.error(charError);
        return;
      }

      if (charResponse.statusCode !== 200) {
        console.error(`Failed to fetch character. Status code: ${charResponse.statusCode}`);
        return;
      }

      const characterData = JSON.parse(charBody);
      console.log(characterData.name);

      fetchCharacterName(index + 1);
    });
  };

  fetchCharacterName(0);
});

