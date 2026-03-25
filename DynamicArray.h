#pragma once
#include <stdexcept>

template<typename T>

class DynamicArray
{
public:
	DynamicArray(int InitialCapacity = 10)
	{
		Size = 0;
		Capacity = InitialCapacity;
		Data = new T[Capacity];
	}

	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}

	void PushBack(const T& Invalue)
	{
		Size++;

		if (Capacity < Size)
		{
			SetCapacity();
			// 1. 늘어난 영역만큼 새로 할당
			T* NewData = new T[Capacity];

			// 2. 원본 복제
			// memcpy()
			for (int i = 0; i < Size - 1; i++)
			{
				NewData[i] = Data[i];
			}

			// 3. 새로 들어온 값 추가
			NewData[Size - 1] = Invalue;

			// 4. 원본 삭제
			delete[] Data;

			// 5. 원본에 새 데이터 포인터 연결
			Data = NewData;
		}
		else
		{
			Data[Size-1] = Invalue;
		}
	
	}

	void SetCapacity()
	{
		Capacity *= 2;
	}

	int GetCapacity()
	{
		return Capacity;
	}

	// 함수 뒤에 const -> readonly 함수
	// 함수 내에서 클래스 변수 수정 불가능
	inline size_t GetSize() const
	{
		return Size;
	}

	// operator overload
	int& operator[](int Index) const
	{
		return Data[Index];
	}

	void RemoveAt(int RemoveIndex)
	{
		if (RemoveIndex >= Size || RemoveIndex < 0)
		{
			throw std::out_of_range("범위를 벗어남");
		}

		for (int i = RemoveIndex; i < Size - 1; i++)
		{
			Data[i] = Data[i + 1];
		}

		Size--;
	}

//protected:
	int* Data;
	size_t Size = 0;
	int Capacity = 1;

	class Iterator
	{
	public:
		Iterator(T* InPointer) : Pointer(InPointer)
		{
		}

		//전위증가
		Iterator& operator++()
		{
			Pointer++;
			return *this;
		}
		//후위증가
		Iterator operator++(int)
		{
			Pointer++;
			return Iterator(Pointer);
		}

		bool operator != (const Iterator & Other)
		{
			return Pointer != Other.Pointer;
		}

		T operator*()
		{
			return *Pointer;
		}

	protected:
		T* Pointer;
	};

	Iterator begin()
	{
		return Iterator(Data);
	}

	Iterator end()
	{
		return Iterator(Data + Size);
	}
};

