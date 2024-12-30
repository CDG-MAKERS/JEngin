#pragma once
#include "CommonInclude.h"

using namespace JMath;

class JEntity
{
public:
	JEntity();
	virtual ~JEntity();

	void SetName(const std::wstring& name) { mName = name; }
	std::wstring& GetName() { return mName;}

private:
	std::wstring mName;
};

