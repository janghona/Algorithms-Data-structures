#include <windows.h>
#include <tchar.h>
#include <list>
#include <set>

//아이템 클래스
class Item
{
	int ItemNO; //아이템 번호
	int Count; //아이템 개수

public:
	Item(int itemNO, int count) : ItemNO(itemNO), Count(count) {}

	int GetItemNO() const { return ItemNO; }
	int GetCount() const { return Count; }
	void AddCount(int add) { Count += add; }

	void Print()
	{
		printf("Item : ItemNO(%d), Count(%d)\n", ItemNO, Count);
	}
};

//인벤토리 클래스
class Inventory
{
	std::list<Item*> ItemList; //아이템 리스트

public:
	//모든 아이템을 출력하는 함수
	void Print()
	{
		if (ItemList.empty())
		{
			printf("Empty");
			return;
		}

		for (auto it = ItemList.begin(); it != ItemList.end(); ++it)
		{
			(*it)->Print();
		}
	}

	//아이템을 찾는 함수
	Item* GetItem(int itemNO)
	{
		for (auto it = ItemList.begin(); it != ItemList.end(); ++it)
		{
			if ((*it)->GetItemNO() == itemNO)
			{
				return (*it);
			}
		}
		return nullptr; //일치하는 아이템이 없을 경우 nullptr 반환
	}

	//아이템을 추가하는 함수
	void AddItem(int itemNO, int count)
	{
		//---------------------------------------------------------------------------------------------------------------
		//★ 문제 1
		//매개변수로 전달된 itemNO 와 같은 아이템이 있을 경우 해당 아이템의 Count 를 매개변수로 전달된 count 만큼 증가시키고,
		//없을 경우 새로운 아이템을 추가하시오.
		//---------------------------------------------------------------------------------------------------------------

		if (GetItem(itemNO) != nullptr) {
			GetItem(itemNO)->AddCount(count);
		}
		else if (GetItem(itemNO) == nullptr) {
			Item* instance = new Item(itemNO, count);
			ItemList.push_back(instance);
		}
	}

	//아이템을 제거하는 함수
	void RemoveItems(std::set<int> removeList)
	{
		//---------------------------------------------------------------------------------------------------------------
		//★ 문제 2
		//매개변수로 전달된 removeList 와 일치하는 모든 아이템을 제거하시오. 동적 할당이 되어있으므로 delete 처리도 필요함!
		//단, removeList 에는 제거하려는 itemID 들이 들어있음.
		//---------------------------------------------------------------------------------------------------------------
		for (auto iter = removeList.begin(); iter != removeList.end(); iter++) {
			Item* tempItem = GetItem(*iter);
			ItemList.remove(tempItem);
			delete tempItem;
		}
	}

	//아이템 리스트를 역순으로 변경하는 함수
	void ReverseItems()
	{
		//---------------------------------------------------------------------------------------------------------------
		//★ 문제 3
		//아이템 리스트의 순서를 역순으로 변경하시오. 
		//---------------------------------------------------------------------------------------------------------------

		ItemList.reverse();
	}
};

int main()
{
	system("cls");
	SetConsoleTitle(_T("문제"));

	//★ [필수] 수험생의 수험번호와 이름을 여기에 기입하여 출력될 수 있도록 함
	//   [주의] 수험번호와 이름이 출력되지 않을 경우 오답처리!
	printf(">> 수험번호 : \n");
	printf(">> 이    름 : 나장호 \n\n");

	Inventory inven;
	inven.Print();

	inven.AddItem(4, 300);
	inven.AddItem(1, 50);
	inven.AddItem(2, 100);
	inven.AddItem(1, 50);
	inven.AddItem(3, 300);
	inven.AddItem(2, 100);
	inven.AddItem(5, 500);
	inven.AddItem(4, 100);
	printf("\n\nAfter add...\n");
	inven.Print();

	inven.RemoveItems({ 2, 3 });
	printf("\nAfter remove...\n");
	inven.Print();

	inven.ReverseItems();
	printf("\nAfter reverse...\n");
	inven.Print();

	getchar();
}
