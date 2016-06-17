// Copyright 1995-2016. All Rights Reserved.
// Created by White.tian 


#include "panda.h"
#include "MoviePlayer.h"
#include "EKGameFrame.h"
#include "EKHUDManager.h"
#include "EKProcedureManager.h"
#include "PandaGameInstance.h"
#include "Procedure_SelectChar.h"



FProcedure_MainCity::FProcedure_MainCity(uint64 inID)
	:FEKProcedureBase(inID)
	/*,isSendLogin(false)*/
{

}

void FProcedure_MainCity::Init()
{
	return FEKProcedureBase::Init();
}

void FProcedure_MainCity::Tick(float inDeltaTime)
{
	FEKProcedureBase::Tick(inDeltaTime);
}

void FProcedure_MainCity::Enter()
{
	FEKProcedureBase::Enter();

	UE_LOG(LogScript, Warning, TEXT("Enter Procedure MainCity %d"), n_ID);

	if (FEKGameFrame::Instance()->SceneManager()->LoadMap(TEXT("City_01")))
	{
		//����loading���档
		if (GWorld == nullptr)
		{
			if (FEKGameFrame::Instance()->SceneManager()->GetWorld() != nullptr)
			{
				// ����ͼ����
				if (true)
				{
					FEKGameFrame::Instance()->SceneManager()->CreateLoadingScreen();
				}
			}
		}

		//ע��Pre Load Mapί�У��ڸ�ί�к����в���loading���档
		delegateHandle = FCoreUObjectDelegates::PreLoadMap.AddRaw(this, &FProcedure_MainCity::PreLoadMap);
	}
}

void FProcedure_MainCity::PreLoadMap()
{
	UE_LOG(LogScript, Warning, TEXT("Enter Procedure MainCity %d PreLoadMap()"), n_ID);

	//FCoreUObjectDelegates::PreLoadMap.RemoveRaw(this, &FProcedure_Login::PreLoadMap);
	FCoreUObjectDelegates::PreLoadMap.Remove(delegateHandle);

	//isAsyncLoadingFinish.exchange(false);

	//if (GetMoviePlayer()->PlayMovie())
	//{
	//	//����ɹ�����loading���棬ע��Post Load Mapί�У��ڸ�ί���н���loading����
	//	FCoreUObjectDelegates::PostLoadMap.AddRaw(this, &FProcedure_Login::PostLoadMap);
	//}

	GetMoviePlayer()->PlayMovie();
	delegateHandle = FCoreUObjectDelegates::PostLoadMap.AddRaw(this, &FProcedure_MainCity::PostLoadMap);
}

void FProcedure_MainCity::PostLoadMap()
{
	UE_LOG(LogScript, Warning, TEXT("Enter Procedure MainCity %d PostLoadMap()"), n_ID);

	//FCoreUObjectDelegates::PostLoadMap.RemoveRaw(this, &FProcedure_Login::PostLoadMap);
	FCoreUObjectDelegates::PostLoadMap.Remove(delegateHandle);

	//���������������̬loading������ʽloading��
	FEKGameFrame::Instance()->HUDManager()->ShowWindow("MainCity");

	//while (!isAsyncLoadingFinish)
	//{
	//	//�������������ģ�����Ҫ�첽ִ�е�loading���ݣ����Ƽ�ʹ������ʽloading��
	//	UE_LOG(LogScript, Warning, TEXT(" !!!! Waiting Loading !!!! "));
	//	//Sleep(1000);
	//}

	/*APlayerController* PC = GWorld->GetFirstLocalPlayerFromController()->GetPlayerController(GWorld);
	ASelectCharPC* SelectPC = Cast<ASelectCharPC>(PC);
	if (SelectPC)
	{
		SelectPC->InitSelectCharScene();
	}*/

	//����loading����
	GetMoviePlayer()->WaitForMovieToFinish();
}

void FProcedure_MainCity::Leave()
{
	FEKProcedureBase::Leave();

	//FEKGameFrame::Instance()->HUDManager()->HideWindow("Login");

	FEKGameFrame::Instance()->HUDManager()->HideWindow("MainCity", true);

	UE_LOG(LogScript, Warning, TEXT("Leave Procedure MainCity %d"), n_ID);
}