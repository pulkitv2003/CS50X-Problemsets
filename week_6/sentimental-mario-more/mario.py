# TODO
while True:
    height = input("Height :")
    try:
        height = int(height)
        if height > 0 and height <= 8:
            break
    except:
        continue
for i in range(1, height + 1):
    print(" "*(height - i)+"#"*i+"  "+"#"*i)
