#pragma once
#include "JResource.h"
//�������� ���ҽ��� �����ؾ��Ѵ�.
//������ ����� �ؽ�ó �� ������ �� �ִ�.
class JResources
{
public:
	template <typename T>
	static T* Find(const std::wstring& key)
	{
		//std::map<std::wstring, JResource*>::iterator
		auto iter = mResources.find(key);
		if (iter == mResources.end())
			return nullptr;

		return dynamic_cast<T*>(iter->second);
	}
	template <typename T>
	static T* Load(const std::wstring& key, const std::wstring& path)
	{
		//�ߺ��� �� ��� �����ͼ� ����ϸ� ��
		T* resource = JResources::Find<T>(key);
		if (resource != nullptr)
			return resource;

		resource = new T();
		//���¿� �´� load �Լ� ȣ��
		if ( FAILED(resource->Load(path) ) )
			assert(false);

		resource->SetName(key);
		resource->SetPath(path);
		mResources.insert(std::make_pair(key, resource));
		return resource;
	}

private:

	static std::map<std::wstring, JResource*> mResources;
};
