//哈希

//哈希表存储结构一般有两种写法，有拉链法和开放寻址法

//作用， 把一堆很大的数映射到一个很小的数 如(0 - 1e9) -> (0 - 1e3)

//拉链法：
int h[N], e[N], ne[N], idx;

//向哈希表中插入一个数
void insert(int x){
	int k = (x % N + N) % N; //这里括号里加N的作用就是为了防止x是一个很大的负数，哈希函数不希望出现负数 
	e[idx] = x; //接下来的操作就是把映射相同的数拉链到这个数的下面，把映射相同的数不断拉链到
	//链表头的后面，就类似于在链表头插入一个数 
	ne[idx] = h[k]; 
	h[k] = idx ++; 
} 

//在哈希表中查询某个数是否存在
bool find(int x){
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i]){
		if (e[i] == x){
			return true;
		}
		return false;
	} 
} 

//拉链法与开放寻址法都要注意N的定义
  
