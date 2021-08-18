import re


def abbreviate(words):
    # delete special characters in the string
    words = re.sub(r"[^a-zA-Z0-9']+", ' ', words)

    # split the string
    words = words.split(' ')

    acronyme = ""

    # create the acronyme
    for word in words:
        acronyme += word[0].upper()

    return acronyme
