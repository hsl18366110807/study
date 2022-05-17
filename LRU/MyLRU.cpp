class MyLRU
{
public:
	MyLRU();
	~MyLRU();
	int IsShortOfPage(int v);
	void SetPageCount(int n);
	float HitPercent();
	DoubleListNode* head;
	DoubleListNode* tail;
private:
	int size;
	int num;
	int success;
	int fail;
	map<int, DoubleListNode*> mp;
};

MyLRU::MyLRU()
{
	num = 0, success = 0, fail = 0;
	head = new DoubleListNode(-1);
	tail = head;
}

MyLRU::~MyLRU()
{
	while (head) {
		DoubleListNode* p = head->next;
		delete(head);
		head = p;
	}
}

float MyLRU::HitPercent(){
	if (success + fail == num) {
		float res = (float)success / num;
		return res;
	}
	else
	{
		cout << "命中次数 + 未命中次数 ！= 总次数";
		return -1.00;
	}
}

void MyLRU::SetPageCount(int n) {
	if (n < 0 || n > 100) {
		size = 5;
		return;
	}
	size = n;
}

int MyLRU::IsShortOfPage(int v) {
	++num;
	map<int, DoubleListNode*>::iterator ite = mp.find(v);
	if (ite != mp.end()) {
		//找到
		DoubleListNode* p = ite->second;
		if (head->next != p) {
			p->pre->next = p->next;
			if (p->next)p->next->pre = p->pre;
			p->next = head->next;
			head->next->pre = p;
			head->next = p;
		}
		if (p == tail) tail = p->pre;
		++success;
		return 1;
	}
	else {
		//未找到
		if (mp.size() < size) {
			//直接插入
			DoubleListNode* p = new DoubleListNode(v);
			p->next = head->next;
			if(head->next)head->next->pre = p;
			head->next = p;
			p->pre = head;
			mp[v] = p;
			if (head == tail) tail = p;
		}
		else {
			DoubleListNode* p = tail;
			tail = tail->pre;
			tail->next = nullptr;
			mp.erase(p->val);
			free(p);
			p = new DoubleListNode(v);
			p->next = head->next;
			if (head->next)head->next->pre = p;
			head->next = p;
			p->pre = head;
			mp[v] = p;
		}
		++fail;
		return 0;
	}
}
