#pragma once
#include<d3dx9.h>


extern LPDIRECT3D9				lpD3D;		// Direct3Dインターフェイス
extern LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDeviceインターフェイス
extern D3DPRESENT_PARAMETERS d3dpp;
extern HWND hwnd;
extern int FPS;

#define	SCRW		1280	// ウィンドウ幅（Width
#define	SCRH		720		// ウィンドウ高さ（Height


#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)


// 頂点フォーマットの定義
struct VERTEX
{
	D3DXVECTOR3 Pos;
	D3DCOLOR Color;
	D3DXVECTOR2 Tex;
};


//Xファイルの定義
struct XFILE {
	LPD3DXMESH lpMesh;			//meshの形状データ	
	DWORD NumMaterial;			//グループの数
	D3DMATERIAL9 *Mat;			//マテリアルの内容　* グループ数分
	LPDIRECT3DTEXTURE9 *Tex;	//Textureの内容 * グループ数分		
};

enum ID{PLAYER_ID, ENEMY_ID};

//雪玉を発射するときに渡すデータの構造体
struct SnowBallInitValue {
	D3DXVECTOR3 shootPos;		//打ち出す位置
	float XAxisAng;				//X軸の回転角度	*Degreeで渡す
	float YAxisAng;				//Y軸の回転角度	*Degreeで渡す
	float powerRate;			//打ち出すパワーの割合	*0~100
	ID id;						//発射したキャラをenumで定義したIDを入れる
};

//当たり判定の球の情報を渡す時に使う構造体
struct CollisionSphere {
	D3DXVECTOR3 pos;
	float radius;
};

void DrawMesh(XFILE *XFile);

//球同士の当たり判定
bool CollisionDetection(CollisionSphere *dataA, CollisionSphere *dataB);

//メッシュに対してのレイ判定
bool MeshCollisionDetection(XFILE *Mesh, D3DXMATRIX *MeshMat, D3DXVECTOR3 *LayPos, D3DXVECTOR3 *LayVec, float *MeshDis);