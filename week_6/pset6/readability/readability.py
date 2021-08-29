def main():
    text = input("text: ")
    
    # words per the whole paragraph
    words = countwords(text)    
    
    # letters per the whole paragraph
    letters = countletters(text)               
     
    # sentences per the whole paragraph
    sentences = countsentences(text)
     
    # letters per 100 words
    L = (100 / words) * letters
    
    # sentences per 100 words
    S = (100 / words) * sentences
    
    # The Coleman-Liau index
    index = (0.0588 * L) - (0.296 * S) - 15.8
     
    if index >= 16:
        print("Grade 16+")
    elif index <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")
    
# calculating the whole words


def countwords(text):
    W = 1
    for i in range(len(text)):
        if text[i] == ' ':
            W += 1
    return W
    

# calculating the whole letters


def countletters(text):
    L = 0
    for i in range(len(text)):
        if text[i].isalpha() == True:
            L += 1
    return L
    
# calculating the whole sentences (.)(?)(!)


def countsentences(text):
    S = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            S += 1
    return S
    

main()