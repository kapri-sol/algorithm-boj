# 2-A
[미로 탐색](https://www.acmicpc.net/problem/2178)

# 2-B
[유기농 배추](https://www.acmicpc.net/problem/1012)

# 2-C
[안전 영역](https://www.acmicpc.net/problem/2468)

# 2-D
[영역 구하기](https://www.acmicpc.net/problem/2583)

# 2-E
[쿼드트리](https://www.acmicpc.net/problem/1992)

# 2-F
[사과 담기 게임](https://www.acmicpc.net/problem/2828)

# 2-G
[빈도 정렬](https://www.acmicpc.net/problem/2910)

# 2-H
[비밀번호 발음하기](https://www.acmicpc.net/problem/4659)

# 2-I
[수학숙제](https://www.acmicpc.net/problem/2870)

# 2-J
[기상캐스터](https://www.acmicpc.net/problem/10709)

# 2-K
[교수가 된 현우](https://www.acmicpc.net/problem/3474)

# 2-L
[NBA 농구](https://www.acmicpc.net/problem/2852)

# 2-M
[영화감독 숌](https://www.acmicpc.net/problem/1436)

# 2-N
[괄호](https://www.acmicpc.net/problem/9012)

# 2-O
[균형잡힌 세상](https://www.acmicpc.net/problem/4949)

# 2-P
[연구소](https://www.acmicpc.net/problem/14502)

# 2-Q 
[치즈](https://www.acmicpc.net/problem/2636)

# 2-R
[트리](https://www.acmicpc.net/problem/1068)

# 문제
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

예를 들어, 다음과 같은 트리가 있다고 하자.

![](https://upload.acmicpc.net/560de878-d961-475e-ada4-e1f0774e5a84/-/preview/)

현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 다음과 같이 변한다. 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.

![](https://upload.acmicpc.net/d46ddf4e-1b82-44cc-8c90-12f76e5bf88f/-/preview/)

이제 리프 노드의 개수는 1개이다.

# 입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

# 출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

# 예제 입력 1
```
5
-1 0 0 1 1
2
```
# 예제 출력 1
```
2
```

# 예제 입력 2
```
5
-1 0 0 1 1
1
```

# 예제 출력 2
```
1
```
# 예제 입력 3
```
5
-1 0 0 1 1
0
```

# 예제 출력 3
```
0
```

# 예제 입력 4
```
9
-1 0 0 2 2 4 4 6 6
4
```
# 예제 출력 4
```
2
```