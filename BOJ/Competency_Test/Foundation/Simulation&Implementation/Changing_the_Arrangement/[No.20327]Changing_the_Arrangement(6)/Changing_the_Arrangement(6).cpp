#include <iostream>
#include <cstring>
using namespace std;
int n, r;
int arr[128][128];
int arr2[128][128];
int gop[8] = { 1,2,4,8,16,32,64,128};
int range;
void one(int jump) {
	for (int a = 0; a < range; a += jump) {
		for (int b = 0; b < range; b += jump) {
			for (int c = 0; c < jump; ++c) {
				for (int d = 0; d < jump; ++d) {
					arr2[a + jump - c - 1][b + d] = arr[a + c][b + d];

				}
			}
		}
	}
	memcpy(arr, arr2, sizeof(arr));
	return;
}
void two(int jump) {
	for (int a = 0; a < range; a += jump) {
		for (int b = 0; b < range; b += jump) {
			for (int c = 0; c < jump; ++c) {
				for (int d = 0; d < jump; ++d) {
					arr2[a + c][b + jump - d - 1] = arr[a + c][b + d];
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

	for (int a = 0; a < gop[n]; ++a) {
		for (int b = 0; b < gop[n]; ++b) {
			cout << arr[a][b] << " ";
		}
		cout << "\n";
	}
	return 0;
}
