#pragma once
#include "JEntity.h"
class JResource abstract : public JEntity //Ãß»ó
{
public:
	JResource(enums::eResourceType type);
	JResource() = delete;
	virtual ~JResource();

	virtual HRESULT Load(const std::wstring& path) = 0;

	const std::wstring& GetPath() { return mPath; }
	void SetPath(const std::wstring& path) { mPath = path; }
private:
	const enums::eResourceType mType;
	std::wstring mPath;
};

//class Texture: public JResource
