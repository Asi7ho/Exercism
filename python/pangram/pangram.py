import string

def is_pangram(sentence):
    sentence = sentence.lower()
    alphabet = list(string.ascii_lowercase)
    nb = [0] * 26

# counting...
    for c in sentence:
        for i in range(len(alphabet)):
            if c == alphabet[i]:
                nb[i] += 1

# verifying if the sentence is a pangram
    for j in range(len(nb)):
        if nb[j] == 0:
            return False

    return True


