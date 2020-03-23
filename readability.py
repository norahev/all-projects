
letter = 0  # lettercounter
word = 0  # wordcounter
sentence = 0  # sentencecounter

text = input("Text: ")  # prompt user for input
length = len(text)  # length of text
if text[0].isalnum():  # if first character is number ot letter set wordcount to 1
    word = 1
for i in range(length):  # check text
    text[i].isalpha()
    if text[i].isalpha():
        letter += 1
    if text[i] == " ":
        word += 1
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentence += 1
# use coleman-liau index
L = (float(letter) / float(word)) * 100
S = (float(sentence) / float(word)) * 100
index = float(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade", round(index))
