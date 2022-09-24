def precision():
    initial=1.0
    final=10.0
    for i in range(0,40):
        print("i=" +str(i))
        print("inital=" +str(initial))
        print("final=" +str(final))
        loop(initial,final)
        initial=initial/10.0
        final=final/10.0
    checkint()
    

def loop(x,y):
    temp=x
    count=1
    while(x<=y):
        print("count =" + str(count))
        x=x+temp
        count=count+1
def checkint():
    x=0.1+0.1+0.1
    y=0.3
    if(x==y):
        print("True x: " +str(x) +" y:" +str(y))
    else:
        print("False x: " +str(x) +" y:" +str(y))
    if(x==0.3):
        print("True x: " +str(x))
    else:
        print("False x: " +str(x) +" y:" +str(y))

precision()

#This also fails at around the same place as c, at i=36, going from 10^-37 to 10^-36
# Python also doesn't have perfect precision, since it fails at order 10^-16 