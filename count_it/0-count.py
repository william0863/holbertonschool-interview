#!/usr/bin/python3
import requests
import re


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries the Reddit API to count occurrences of keywords in the titles of hot posts
    in a given subreddit. The function uses pagination to fetch all hot posts.

    Args:
        subreddit (str): The subreddit to query.
        word_list (list): A list of keywords to count.
        after (str, optional): The ID of the next set of posts to fetch. Default is None.
        word_count (dict, optional): A dictionary to keep track of word counts. Default is None.

    Returns:
        None: Prints results directly.
    """
    if word_count is None:
        word_count = {word.lower(): 0 for word in word_list}

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'limit': 100, 'after': after}
    headers = {'User-Agent': 'Mozilla/5.0'}

    try:
        response = requests.get(url, params=params, headers=headers, timeout=10)
        response.raise_for_status()
    except requests.exceptions.RequestException:
        return

    data = response.json()
    if 'data' not in data or 'children' not in data['data']:
        return

    for post in data['data']['children']:
        title = post['data']['title'].lower()
        for word in word_list:
            word_lower = word.lower()
            word_count[word_lower] += len(re.findall(r'\b' + re.escape(word_lower) + r'\b', title))

    after = data['data'].get('after', None)
    if after:
        count_words(subreddit, word_list, after, word_count)
    else:
        sorted_counts = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")

