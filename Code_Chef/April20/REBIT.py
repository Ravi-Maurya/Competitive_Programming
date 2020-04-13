MOD = 998244353

def mod_Inverse(num,mod):
    modulo = mod
    mod_Inv = 1
    y = 0
    if mod == 1:
        return 0
    while(num>1):
        quot = num//mod
        tmp = mod
        mod = num%mod
        num = tmp
        tmp = y

        y = mod_Inv - quot*y
        mod_Inv = tmp
    if (mod_Inv<0):
        mod_Inv += modulo
    return mod_Inv

def convert(expression):
    stack = []
    stack.append(-1)
    converted = ""
    for ch in expression:
        if ch == '(':
            stack.append(ch)
        elif ch == '#':
            converted += '#'
        elif ch == ')':
            while stack[-1]!=-1 and stack[-1] != '(':
                converted += stack.pop()
            if stack[-1] == '(':
                stack.pop()
        else:
            while stack[-1] == '|' or stack[-1] == '&' or stack[-1]=='^':
                converted += stack.pop()
            stack.append(ch)
    while stack[-1] != -1:
        converted += stack.pop()
    return converted

def operation(operator, left, right):
    probability = [ [1,4], [1,4], [1,4], [1,4] ]
    if operator == '|':
        probability[0][0] = left[0][0] * right[0][0]
        probability[0][1] = left[0][1] * right[0][1]

        probability[2][0] = left[2][0] * right[2][0] + left[0][0] * right[2][0] + left[2][0] * right[0][0]
        probability[2][1] = left[2][1] * right[2][1]

        probability[3][0] = left[3][0] * right[0][0] + left[0][0] * right[3][0] + left[3][0] * right[3][0]
        probability[3][1] = left[3][1] * right[0][1]

        probability[1][0] = (left[0][1] * right[0][1]) -  (probability[0][0] + probability[2][0] + probability[3][0])
        probability[1][1] = left[0][1] * right[0][1]
    
    elif operator == '&':
        probability[1][0] = left[1][0] * right[1][0]
        probability[1][1] = left[1][1] * right[1][1]

        probability[2][0] = left[2][0] * right[1][0] + left[1][0] * right[2][0] + left[2][0] * right[2][0]
        probability[2][1] = left[1][1] * right[1][1]

        probability[3][0] = left[3][0] * right[1][0] + left[1][0] * right[3][0] + left[3][0] * right[3][0]
        probability[3][1] = left[1][1] * right[1][1]

        probability[0][0] = (left[1][1] * right[1][1]) - (probability[1][0] + probability[2][0] + probability[3][0])
        probability[0][1] = left[1][1] * right[1][1]
    
    elif operator == '^':
        probability[0][0] = left[0][0] * right[0][0] + left[1][0] * right[1][0] + left[2][0] * right[2][0] + left[3][0] * right[3][0]
        probability[0][1] = left[0][1] * right[0][1]

        probability[1][0] = left[0][0] * right[1][0] + left[1][0] * right[0][0] + left[2][0] * right[3][0] + left[3][0] * right[2][0]
        probability[1][1] = left[0][1] * right[0][1]

        probability[2][0] = left[2][0] * right[0][0] + left[0][0] * right[2][0] + left[1][0] * right[3][0] + left[3][0] * right[1][0]
        probability[2][1] = left[0][1] * right[0][1]

        probability[3][0] = left[3][0] * right[0][0] + left[0][0] * right[3][0] + left[1][0] * right[2][0]+  left[2][0] * right[1][0]
        probability[3][1] = left[0][1] * right[0][1]
    
    return probability

def evaluate(expression):
    stack = []
    for ch in expression:
        if ch == '#':
            stack.append([ [1,4], [1,4], [1,4], [1,4] ])
        else:
            left = stack.pop()
            right = stack.pop()
            stack.append(operation(ch,left,right))
    return stack[-1]

def main():
    expression = input()
    postfix = convert(expression)
    res = evaluate(postfix)
    ans = ""
    for i in range(0,4):
        ans += str((res[i][0]*mod_Inverse(res[i][1],MOD))%MOD)
    print(ans)

T = int(input())
for _ in range(T):
    main()