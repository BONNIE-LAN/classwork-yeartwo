string=input().strip()
words=string.split()
careers={}
for word in words:
    if word in careers:
        careers[word]+=1
    else:
        careers[word]=1
sorted_career=sorted(careers.items(),key=lambda x:-x[1])
for word,count in sorted_career:
    print(f"{word}:{count}")




