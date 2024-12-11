#pragma once
#include "JResource.h"
//많은양의 리소스를 관리해야한다.
//종류가 오디오 텍스처 등 많아질 수 있다.
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
		//중복이 될 경우 가져와서 사용하면 됨
		T* resource = JResources::Find<T>(key);
		if (resource != nullptr)
			return resource;

		resource = new T();
		//형태에 맞는 load 함수 호출
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

