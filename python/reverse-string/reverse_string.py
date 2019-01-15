def reverse(text):
    N = len(text)

    reverseText = ""

    for i in range(N):
        reverseText += text[N - 1 - i]

    return reverseText
