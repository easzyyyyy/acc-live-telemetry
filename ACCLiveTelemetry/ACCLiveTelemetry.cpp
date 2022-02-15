// EaszyACCData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include "SharedFileOut.h"

#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <cmath>

#pragma optimize("", off)

using namespace std;

struct SMElement
{
	HANDLE hMapFile;
	LPVOID mapFileBuffer;
};

SMElement m_physics;
SMElement m_graphics;
SMElement m_static;

string MAP_FAILED = "CreateFileMapping failed";
string MAP_VIEW_FAIL = "MapViewOfFile failed";

void initPhysics()
{
	TCHAR szName[] = TEXT("Local\\acpmf_physics");

	m_physics.hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SPageFilePhysics), szName);
	if (!m_physics.hMapFile)
	{
		cout << MAP_FAILED << endl;
		return;
	}

	m_physics.mapFileBuffer = MapViewOfFile(m_physics.hMapFile, FILE_MAP_READ, 0, 0, sizeof(SPageFilePhysics));
	if (!m_physics.mapFileBuffer)
	{
		cout << MAP_VIEW_FAIL << endl;
	}
}

void initGraphics()
{
	TCHAR szName[] = TEXT("Local\\acpmf_graphics");

	m_graphics.hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SPageFileGraphic), szName);
	if (!m_graphics.hMapFile)
	{
		cout << MAP_FAILED << endl;
		return;
	}
	m_graphics.mapFileBuffer = MapViewOfFile(m_graphics.hMapFile, FILE_MAP_READ, 0, 0, sizeof(SPageFileGraphic));
	if (!m_graphics.mapFileBuffer)
	{
		cout << MAP_VIEW_FAIL << endl;
	}
}

void initStatic()
{
	TCHAR szName[] = TEXT("Local\\acpmf_static");

	m_static.hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SPageFileStatic), szName);
	if (!m_static.hMapFile)
	{
		cout << MAP_FAILED << endl;
		return;
	}

	m_static.mapFileBuffer = MapViewOfFile(m_static.hMapFile, FILE_MAP_READ, 0, 0, sizeof(SPageFileStatic));
	if (!m_static.mapFileBuffer)
	{
		cout << MAP_VIEW_FAIL << endl;
	}
}

void dismiss(SMElement element)
{
	UnmapViewOfFile(element.mapFileBuffer);
	CloseHandle(element.hMapFile);
}

void printData(string name, float value)
{
	cout << name.c_str() << " : " << value << endl;
}

template <typename T, unsigned S>
inline void printData(const string name, const T(&v)[S])
{
	cout << name.c_str() << " : ";

	for (int i = 0; i < S; i++)
	{
		cout << v[i];
		if (i < S - 1)
		{
			cout << " , ";
		}
	}
	cout << endl;
}

template <typename T, unsigned S, unsigned S2>
inline void printData2(const string name, const T(&v)[S][S2])
{
	cout << name.c_str() << " : ";

	for (int i = 0; i < S; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < S2; j++) {
			cout << v[i][j];
			if (j < S2 - 1)
			{
				cout << " , ";
			}
		}
		cout << ";" << endl;
	}
}

int main(int argc, _TCHAR* argv[])
{
	initPhysics();
	initGraphics();
	initStatic();

	while (true)
	{
		SPageFilePhysics* phy = (SPageFilePhysics*)m_physics.mapFileBuffer;
		SPageFileGraphic* gra = (SPageFileGraphic*)m_graphics.mapFileBuffer;
		SPageFileStatic* sta = (SPageFileStatic*)m_static.mapFileBuffer;

		cout << round(phy->speedKmh);

		string ruptor = (phy->rpms > 0.99 * sta->maxRpm) ? "Rupture" : "OK";
		cout << " " << ruptor << endl;
	}

	dismiss(m_graphics);
	dismiss(m_physics);
	dismiss(m_static);

	return 0;
}
