# Unreal Engine 5 - Steam Multiplayer Session System

## **프로젝트 개요**
이 프로젝트는 **Unreal Engine 5.5.3**을 기반으로 **Steam 멀티플레이 세션 시스템**을 구축하는 방법을 정리한 것입니다.

구현된 주요 기능:
- **Steam 연동**: Advanced Sessions 플러그인 활용
- **세션 시스템**: 세션 생성 및 참가 기능 구현
- **친구 시스템**: Steam 친구 목록 UI 및 초대 기능
- **멀티플레이 환경**: Listen Server 방식 적용

## **참고한 자료 및 출처**
이 프로젝트는 아래의 자료를 참고하여 진행되었습니다:

### 📌 **블로그 포스팅**
1. **Steam 멀티플레이 환경 설정**  
   - 출처: [손사장 블로그 - Unreal Engine Online Subsystem Steam 적용하기 설정](https://sonsazang.tistory.com/122)

2. **Steam 세션 및 친구 초대 기능 구축**  
   - 출처: [손사장 블로그 - 세션 생성 후 세션 입장 테스트 하기](https://sonsazang.tistory.com/123)

### 🎥 **참고해서 진행한 유튜브 강좌**
- **How To Create A Steam Multiplayer Lobby System (Pitchfork Academy - MizzoFrizzo & Co.)**  
  - 참고 재생목록: [YouTube Playlist](https://www.youtube.com/playlist?list=PLQWbYU4V4BS3v1UuDk9pNIFqMFGdApWw8)
  - ⚠️ **참고:** 본 프로젝트에서는 **로비 시스템을 구현하지 않았으며**, 세션 생성 및 입장, 친구 초대 기능까지만 적용했습니다.

## **설치 및 실행 방법**

### 1️⃣ **필수 플러그인 설치**
Steam 멀티플레이 기능을 사용하기 위해 **Advanced Sessions Plugin**을 설치해야 합니다.
- 다운로드: [Advanced Sessions Plugin (v5.5.4)](https://vreue4.com/advanced-sessions-binaries)
- `Plugins` 폴더 생성 후 아래 폴더 복사:
  - `AdvancedSteamSessions`
  - `AdvancedSessions`

### 2️⃣ **OnlineSubsystemSteam 설정**
`Config/DefaultEngine.ini` 파일의 하단에 아래 설정을 추가합니다:

```ini
[/Script/Engine.GameEngine]
+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="OnlineSubsystemSteam.SteamNetDriver",DriverClassNameFallback="OnlineSubsystemUtils.IpNetDriver")

[OnlineSubsystem]
DefaultPlatformService=Steam

[OnlineSubsystemSteam]
bEnabled=true
SteamDevAppId=480

[/Script/OnlineSubsystemSteam.SteamNetDriver]
NetConnectionClassName="OnlineSubsystemSteam.SteamNetConnection"
```

### 3️⃣ **블루프린트 및 기능 구현**
- `BP_GameInstance` 설정 및 `Create Session` 이벤트 추가
- `W_FriendList` 및 `W_Friend` UI 구현
- `OnSessionInviteAccepted` 이벤트 추가하여 친구 초대 기능 구현

### 4️⃣ **빌드 및 실행**
1. **클린 빌드** 진행 (`.vs`, `Binaries`, `Intermediate`, `Saved` 폴더 삭제 후 프로젝트 리빌드)
2. `Binaries/Win64` 폴더에 `steam_appid.txt` 생성 후 `480` 입력
3. 에디터에서 `Standalone Game` 실행 후 **Shift + Tab** 키로 Steam 오버레이 확인

## **버그 수정 사항**
- 친구 리스트 UI 갱신 문제: `Set Timer by Event`의 `Looping` 속성을 `True`로 변경하여 해결

---
이 프로젝트는 **언리얼 엔진 기반의 Steam 멀티플레이 세션 및 친구 초대 시스템을 구축**하고자 하는 개발자를 위한 가이드입니다.
추후 **매치메이킹, 서버 브라우징, 게임 룸 관리 기능** 등을 추가적으로 구현할 수 있습니다. 🚀

