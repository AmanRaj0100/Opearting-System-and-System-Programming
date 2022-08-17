import json

with open("Day 1 Recall Quiz.quiz", "r") as fa:
    dfa = json.load(fa)

with open("final_recal_quiz.txt", "w") as fb:
    
    for val in dfa["results"]:
        fb.write(str(val))
        fb.write("\n------------\n")
