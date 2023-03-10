'''

Jeongeun in charge
Update: 2023.1.26

정수 삼각형

문제 설명:

위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

제한사항:

삼각형의 높이는 1 이상 500 이하입니다.
삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.

'''

'''
문제접근:
꼭대기에서부터 삼각형 배열의 값들을 업데이트 해 가며 마지막 바닥 인덱스 배열에서 최댓값을 선정하면 된다.
'''

def solution(triangle):
    answer = 0
    for r in range(1,len(triangle)):
        for c in range(len(triangle[r])):
            if c==0:
                triangle[r][c]+=triangle[r-1][c]
            elif c==r:
                triangle[r][c]+=triangle[r-1][c-1]
            else:
                triangle[r][c]+=max(triangle[r-1][c],triangle[r-1][c-1])
                
    answer=max(triangle[-1])
                
    return answer