문제 사이트 : https://www.acmicpc.net/problem/20327

문제 설명 :

    크기가 2N×2N인 배열이 있을 때, 배열에 연산을 R번 적용하려고 한다.
    
    연산은 8가지가 있고, 연산에는 단계 ℓ (0 ≤ ℓ < N)이 있다. 
    
    단계 ℓ은 배열을 부분 배열로 나눌때 사용하는 값이며, 부분 배열의 크기는 2ℓ×2ℓ가 되어야 한다.
    
    단계는 연산을 수행할때마다 정한다.

    다음은 크기가 23×23 배열을 단계 ℓ의 값에 따라 부분 배열로 나눈 것이다. 같은 부분 배열은 같은 색상으로 표시했다.
  --------------------[ ℓ = 0 ] ----------------------------------------- [ ℓ = 1 ] -----------------------------------------[ ℓ = 2 ]------------------------
                                         
<img src="https://user-images.githubusercontent.com/57944215/145169026-2b5ee2d9-7cea-4375-aa44-f21aadd2df94.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145169265-3e1809a3-e5b6-4e1c-8792-5ac71e06f005.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145169336-57b9c367-db6f-4235-b7a2-e99f5f141813.jpg" width="32%" height="50%">
      
    
1번 연산은 각 부분 배열을 상하 반전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 1, 1번 연산 적용 ]----------------------------
                      
<img src="https://user-images.githubusercontent.com/57944215/145169892-000d4c77-24c9-4adc-9038-2b7f31862a51.jpg" width="32%" height="50%">  <img src = "https://user-images.githubusercontent.com/57944215/145169985-e69e0658-cd76-4d3c-b02c-962ed63a6d37.jpg" width="32%" height="50%">

2번 연산은 각 부분 배열을 좌우 반전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 2, 2번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170547-1423f189-578b-4425-b45a-42c03a2526f6.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170552-83cf680e-e9c2-4048-90bf-672a460f6c4c.jpg" width="32%" height="50%">

3번 연산은 각 부분 배열을 오른쪽으로 90도 회전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 1, 3번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170688-571f8ca4-418d-4f38-b4a3-4d07de2a250d.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170695-31c37adf-2332-486b-b109-480f4c0832d9.jpg" width="32%" height="50%">


4번 연산은 각 부분 배열을 왼쪽으로 90도 회전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 2, 4번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170702-bf356181-fd02-477a-a966-51e7b1feabb5.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170708-4c6f68e2-691f-455b-9d84-f72f60b6ee61.jpg" width="32%" height="50%">

	
5, 6, 7, 8번 연산은 부분 배열을 한 칸으로 생각하고 적용시킨다. 

즉, 부분 배열의 안에 있는 값은 변하지 않는다.

5번 연산은 배열을 상하 반전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 2, 5번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170723-133bd2fa-daa8-488e-af75-5a3d6e097ad6.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170730-93aab118-8f53-4aff-b1d3-4aa55db9b688.jpg" width="32%" height="50%">

	
6번 연산은 배열을 좌우 반전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 1, 6번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170738-bb7e8616-53bf-4737-97aa-34b2b38c3dc9.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170741-b99a2c10-b64a-44af-87ec-d4b93ed3f594.jpg" width="32%" height="50%">

	
7번 연산은 오른쪽으로 90도 회전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 1, 7번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170751-040e211f-c4eb-4082-81c2-bd912a31d4f8.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170779-61eda007-3cfe-4578-9b05-2b10739a8607.jpg" width="32%" height="50%">

	
8번 연산은 왼쪽으로 90도 회전시키는 연산이다.

-------------------[ 배 열 ]>>>>>>>>>>>>>>>>       [ ℓ = 2, 8번 연산 적용 ]----------------------------
<img src="https://user-images.githubusercontent.com/57944215/145170788-533377c2-15d5-4f4a-845e-23c8cd26e237.jpg" width="32%" height="50%"> <img src="https://user-images.githubusercontent.com/57944215/145170792-0e492e5e-c6a1-4063-9f93-c78a9e1ae3c0.jpg" width="32%" height="50%">

	

입력

    첫째 줄에 N, R이 주어진다. 

    둘째 줄부터 2N개의 줄에 배열의 원소 A[i][j]가 주어진다.

    i번째 줄의 j번째 정수는 A[i][j]를 의미한다.

    다음 R개의 줄에 배열에 적용시켜야 하는 연산이 한 줄에 하나씩 주어진다. 

    연산은 두 정수 k, ℓ로 이루어져 있고, k번 연산을 단계 ℓ로 적용한다는 의미이다.

출력

    입력으로 주어진 배열에 R개의 연산을 순서대로 수행한 결과를 출력한다.

제한

    1 ≤ N ≤ 7
    1 ≤ R ≤ 1,000
    1 ≤ k ≤ 8
    0 ≤ ℓ < N
    -999 ≤ A[i][j] ≤ 999

예제 입력 1 

    3 8
    1 2 3 4 5 6 7 8
    9 10 11 12 13 14 15 16
    17 18 19 20 21 22 23 24
    25 26 27 28 29 30 31 32
    33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48
    49 50 51 52 53 54 55 56
    57 58 59 60 61 62 63 64
    1 1
    2 2
    3 1
    4 2
    5 2
    6 1
    7 1
    8 2

예제 출력 1 

    64 63 62 61 60 59 58 57
    56 55 54 53 52 51 50 49
    48 47 46 45 44 43 42 41
    40 39 38 37 36 35 34 33
    32 31 30 29 28 27 26 25
    24 23 22 21 20 19 18 17
    16 15 14 13 12 11 10 9
    8 7 6 5 4 3 2 1

예제 입력 2 

    3 4
    1 2 3 4 5 6 7 8
    9 10 11 12 13 14 15 16
    17 18 19 20 21 22 23 24
    25 26 27 28 29 30 31 32
    33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48
    49 50 51 52 53 54 55 56
    57 58 59 60 61 62 63 64
    1 0
    2 0
    3 0
    4 0

예제 출력 2 

    1 2 3 4 5 6 7 8
    9 10 11 12 13 14 15 16
    17 18 19 20 21 22 23 24
    25 26 27 28 29 30 31 32
    33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48
    49 50 51 52 53 54 55 56
    57 58 59 60 61 62 63 64

예제 입력 3 

    3 4
    1 2 3 4 5 6 7 8
    9 10 11 12 13 14 15 16
    17 18 19 20 21 22 23 24
    25 26 27 28 29 30 31 32
    33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48
    49 50 51 52 53 54 55 56
    57 58 59 60 61 62 63 64
    5 0
    6 0
    7 0
    8 0

예제 출력 3 

    64 63 62 61 60 59 58 57
    56 55 54 53 52 51 50 49
    48 47 46 45 44 43 42 41
    40 39 38 37 36 35 34 33
    32 31 30 29 28 27 26 25
    24 23 22 21 20 19 18 17
    16 15 14 13 12 11 10 9
    8 7 6 5 4 3 2 1

예제 입력 4 

    3 8
    1 2 3 4 5 6 7 8
    9 10 11 12 13 14 15 16
    17 18 19 20 21 22 23 24
    25 26 27 28 29 30 31 32
    33 34 35 36 37 38 39 40
    41 42 43 44 45 46 47 48
    49 50 51 52 53 54 55 56
    57 58 59 60 61 62 63 64
    1 2
    8 1
    7 2
    4 0
    3 2
    5 1
    6 1
    2 2
    
예제 출력 4 

    45 37 47 39 41 33 43 35
    46 38 48 40 42 34 44 36
    61 53 63 55 57 49 59 51
    62 54 64 56 58 50 60 52
    13 5 15 7 9 1 11 3
    14 6 16 8 10 2 12 4
    29 21 31 23 25 17 27 19
    30 22 32 24 26 18 28 20
  
 

풀이 알고리즘

    1. 주어진 8가지 동작을 구현하는 문제입니다.
    
    2. 1~4번 동작은 주어진 ℓ의 값에 따라 달라지는 부분배열을 하나의 배열로 취급하여
    2^ℓ * 2^ℓ 개 존재하는 모든 부분배열에 대해 동작을 수행하였습니다.
    
    3. 5~6번 동작은 주어진 ℓ의 값에 따라 나눠지는 부분배열을 하나의 원소로 보았고
    동작에 따라 부분배열이 존재해야하는 위치를 찾은 뒤, 안의 원소들을 위치만큼 더해주는 방식으로 
    구현하였습니다.

[ 구 현 ]

    #include <iostream>
    #include <cstring>
    using namespace std;
    int n, r;
    int arr[128][128]; // 본 배열
    int arr2[128][128]; // 임시배열
    int gop[8] = { 1,2,4,8,16,32,64,128};
    int range; // 전체 배열의 범위
    
    void one(int jump) { // 1번 동작
    
      for (int a = 0; a < range; a += jump) {
        for (int b = 0; b < range; b += jump) {
        // range * range 크기의 전체배열에서 주어진 ℓ에 따라 달라지는 jump값을 매개변수로 입력아 for문실시
        // jump값은 ℓ에 의해 나눠지는 부분배열의 길이.
        // 하나의 부분배열의 시작위치가( a , b )이라면, 이 배열의 오른쪽에 있는 다른 부분배열의 위치는
        // ( a , b+2^ℓ ) 이므로, 2^ℓ만큼씩 이동시켜가며 부분배열 탐색. jump = 2^ℓ
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[a + jump - c - 1][b + d] = arr[a + c][b + d];
              // 상,하 반전이므로 (c,d)의 위치에 있는 원소와 (jump-c-1,d)에 있는 원소의 위치 바꾸기.
              // 하지만 부분배열이므로 현재 부분배열의 행 위치 a, 열 위치 b를 더하여 
              // (a+jump-c-1,b+d) <-> (a+c , b+d)의 위치 바꾸기.

            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr)); // 값이 입력된 arr2배열을 arr배열에 복사
      return;
    }
    void two(int jump) {
      for (int a = 0; a < range; a += jump) {
        for (int b = 0; b < range; b += jump) {
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[a + c][b + jump - d - 1] = arr[a + c][b + d];
              // 좌,우 반전이므로 (c,d)의 위치에 있는 원소와 (c,jump-d-1)에 있는 원소의 위치 바꾸기.
              // 하지만 부분배열이므로 현재 부분배열의 행 위치 a, 열 위치 b를 더하여 
              // (a+c,b+jump-d-1) <-> (a+c , b+d)의 위치 바꾸기.
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;
    }

    void three(int jump) {
      for (int a = 0; a < range; a += jump) {
        for (int b = 0; b < range; b += jump) {
          for (int c = 0; c < jump; ++c) {
            int y = jump - c - 1;
            for (int d = 0; d < jump; ++d) {
              int x = d;
              arr2[a + x][b + y] = arr[a + c][b + d];
              // 시계방향으로 90도 회전이므로 (c,d)의 위치에 있는 원소와 (d,jump-1-c)에 있는 원소의 위치 바꾸기.
              // 하지만 부분배열이므로 현재 부분배열의 행 위치 a, 열 위치 b를 더하여 
              // (a+d,b+jump-1-c) <-> (a+c , b+d)의 위치 바꾸기.
              // x = d, y = jump-c-1
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;
    }
    void four(int jump) {
      for (int a = 0; a < range; a += jump) {
        for (int b = 0; b < range; b += jump) {
          for (int c = 0; c < jump; ++c) {
            int y = c;
            for (int d = 0; d < jump; ++d) {
              int x = jump - d - 1;
              arr2[a + x][b + y] = arr[a + c][b + d];
              // 반시계방향으로 90도 회전이므로 (c,d)의 위치에 있는 원소와 (jump-d-1,c)에 있는 원소의 위치 바꾸기.
              // 하지만 부분배열이므로 현재 부분배열의 행 위치 a, 열 위치 b를 더하여 
              // (a+jump-d-1,b+c) <-> (a+c , b+d)의 위치 바꾸기.
              // x = jump-d-1, y = c
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;
    }
    void five(int jump) {
      int test = gop[n] - jump;
      for (int a = 0; a < range / 2; a += jump) {
        for (int b = 0; b < range; b += jump) {
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[test - a + c][b + d] = arr[a + c][b + d];
              arr2[a + c][b + d] = arr[test - a + c][b + d];
              // 부분배열을 하나의 원소로 보는 연산으로
              // 부분배열이 상하반전 했을 때 위치해야하는 위치를 찾은 뒤,
              // 부분배열의 원소에 해당 위치값 더하기
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;
    }
    void six(int jump) {
      int test = gop[n] - jump;
      for (int a = 0; a < range; a += jump) {
        for (int b = 0; b < range / 2; b += jump) {
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[a + c][test - b + d] = arr[a + c][b + d];
              arr2[a + c][b + d] = arr[a + c][test - b + d];
              // 부분배열을 하나의 원소로 보는 연산으로
              // 부분배열이 좌우반전 했을 때 위치해야하는 위치를 찾은 뒤,
              // 부분배열의 원소에 해당 위치값 더하기
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;


    }
    void seven(int jump) {
      int count = range / jump;
      for (int a = 0; a < range; a += jump) {
        int y = (count - a / jump - 1) * jump;
        for (int b = 0; b < range; b += jump) {
          int x = b;
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[x + c][y + d] = arr[a + c][b + d];
              // 부분배열을 하나의 원소로 보는 연산으로
              // 부분배열이 시계방향 90도 이동 했을 때 위치해야하는 위치를 찾은 뒤,
              // 부분배열의 원소에 해당 위치값 더하기
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;

    }
    void eight(int jump) {
      int count = range / jump;
      for (int a = 0; a < range; a += jump) {
        int y = a;
        for (int b = 0; b < range; b += jump) {
          int x = (count - b / jump - 1) * jump;
          for (int c = 0; c < jump; ++c) {
            for (int d = 0; d < jump; ++d) {
              arr2[x + c][y + d] = arr[a + c][b + d];
              // 부분배열을 하나의 원소로 보는 연산으로
              // 부분배열이 반시계 90도 이동 했을 때 위치해야하는 위치를 찾은 뒤,
              // 부분배열의 원소에 해당 위치값 더하기
            }
          }
        }
      }
      memcpy(arr, arr2, sizeof(arr));
      return;


    }
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //freopen("Input.txt", "r", stdin);
      cin >> n >> r;
      for (int a = 0; a < gop[n]; ++a) {
        for (int b = 0; b < gop[n]; ++b) {
          cin >> arr[a][b];
        }
      }
      int command, lv;
      range = gop[n];
      while (r--) {
        cin >> command >> lv;
        switch (command) {
        case 1:
          one(gop[lv]);
          break;
        case 2:
          two(gop[lv]);
          break;
        case 3:
          three(gop[lv]);
          break;
        case 4:
          four(gop[lv]);
          break;
        case 5:
          five(gop[lv]);
          break;
        case 6:
          six(gop[lv]);
          break;
        case 7:
          seven(gop[lv]);
          break;
        case 8:
          eight(gop[lv]);
          break;
        default:
          break;
        }
      }

      for (int a = 0; a < gop[n]; ++a) { // 모든 연산이 끝난 후 값 출력
        for (int b = 0; b < gop[n]; ++b) {
          cout << arr[a][b] << " ";
        }
        cout << "\n";
      }
      return 0;
    }

