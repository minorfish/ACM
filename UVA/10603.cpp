#include<stdio.h>  
#include<string.h>  

const int N = 3;  
const int M = 205;  
int t, vis[M][M], dis[M * M], q[M*M], min, min_w, flag;  

struct state{  

	int capacity[N];  
}st[M * M];  


void cmp(state s, int x, int d){  

	for(int i = 0; i < N; i++){        

		if(s.capacity[i] == d){  

			if(!flag)  
				min_w = dis[x];  
			else if(dis[x] < min_w)  
				min_w = dis[x];  
			flag = 1;  
		}  
		else {  

			int n = d - s.capacity[i];  
			if(n && n < min)  
				min = n;  
		}  
	}  
}  

void search(int n, int d) {  

	for(int i = 1; i < n; i++)  
		for(int j = 0; j < 3; j++){  

			if(st[i].capacity[j] == d - min){  

				if(dis[i] < min_w)  
					min_w = dis[i];  
			}  
		}  
}  

int bfs(int d){  

	vis[st[1].capacity[0]][st[1].capacity[1]] = 1;  
	int front = 1, rear = 2;  
	while(front < rear){  

		state &s = st[front];  
		cmp(s, front, d);  
		for(int i = 0; i < N; i++)  
			for(int j = 0; j < N; j++) {  

				if(i != j && s.capacity[i] && s.capacity[j] < st[0].capacity[j]) {  

					state &s1 = st[rear];  
					memcpy(&s1, &s, sizeof(s));  
					s1.capacity[j] += s.capacity[i];  
					if(s1.capacity[j] > st[0].capacity[j]){  

						s1.capacity[i] = s1.capacity[j] - st[0].capacity[j];  
						s1.capacity[j] = st[0].capacity[j];  
					}  
					else  
					s1.capacity[i] = 0;  
					dis[rear] = dis[front] + s.capacity[i] - s1.capacity[i];  
					if(!vis[s1.capacity[0]][s1.capacity[1]]){  

						rear++;  
						vis[s1.capacity[0]][s1.capacity[1]] = 1;  
					}         
				}  
			}  
		front++;  
	}  
	return rear;  
}  


int main() {  

	scanf("%d", &t);  
	while(t--){  

		int i, d;  
		for(i = 0; i < N; i++)  
			scanf("%d", &st[0].capacity[i]);  
		scanf("%d", &d);  
		st[1].capacity[0] = 0;  
		st[1].capacity[1] = 0;  
		st[1].capacity[2] = st[0].capacity[2];  
		memset(dis, 0, sizeof(dis));  
		memset(vis, 0, sizeof(vis));  
		flag = 0;  
		int rear = bfs(d);  
		if(flag)  
			printf("%d %d\n", min_w, d);  
		else{  

			min_w = dis[rear - 1];  
			search(rear, d);  
			printf("%d %d\n", min_w, d - min);  

		}             

	}  
	return 0;  
}  
