import cs50

text = cs50.get_string("Text: ")


def count_words(text):
    words = 1
    for i in text:
        if i == " ":
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in text:
        if i in [".", "!", "?"]:
            sentences += 1
    return sentences


def count_letters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def check(index):
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print("Grade ", round(index))


L = count_letters(text) / count_words(text) * 100
S = count_sentences(text) / count_words(text) * 100
index = 0.0588 * L - 0.296 * S - 15.8
check(index)
