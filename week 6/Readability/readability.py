from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 0
sentences = 0

text = text.lower()

counterLetter = len(
    text.replace(" ", "")
    .replace("!", "")
    .replace("?", "")
    .replace("'", "")
    .replace(".", "")
    .replace(",", "")
)
counterWords = len(text.split(" "))
counterSentences = len(text.replace("!", ".").replace("?", ".").split(".")) - 1

L = float(counterLetter) * 100 / float(counterWords)
S = float(counterSentences) * 100 / float(counterWords)
index = 0.0588 * L - 0.296 * S - 15.8


if index >= 16:
    print("Grade 16+")
elif index <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(index + 0.5)}")
