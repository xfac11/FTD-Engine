#pragma once
namespace FTD
{
	template <typename T>
	class Container
	{
	public:
		Container();
		~Container();

		void clean();
		void erase(int index);
		void pushback(T item);

	private:
		T* *container;
		int nrOfItems;
		int capacity;

	};
}
