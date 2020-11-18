# **Nanny-I for Linux**
이  프로젝트는 개방형OS 기반 업무환경 전환을 위하여 문서 파일 완전 삭제, 문서 백업 및 문서 복원 기능을 포함한 자료저장방지 솔루션을 개발합니다.

## 개발대상 개방형OS
* 구름OS 
* 티맥스OS
* 하모니카OS
* 우분투OS

자료저장방지 솔루션은 개방형 OS 기반 실시간 탐지, 문서 파일 포맷 인식, 문서 파일 완전 삭제, 문서 백업 및 문서 복원 기능을 제공하며, 통합 정책 관리 및 로그 통합 조회 등 통합 관리 기능을 부가적으로 제공합니다.
기존 자료저장방지 솔루션은 Windows 운영체제 위주로 지원되고 있어 개방형 OS 확산을 위하여 필수 보안 소프트웨어의 개발 및 지원이 시급합니다.

## **주요 개발항목**
* 리눅스 부팅 시 특성 확장자의 문서 검색 및 삭제
* 문서 및 압축파일 등 삭제 대상 확장자 설정
* 파일의 헤더 정보를 비교하여 문서 파일 식별 삭제
* 삭제된 파일을 복구할 수 없도록 영구 삭제
* 지정된 디렉토리에서 생성 완료된 파일 탐지 및 삭제
* 특정 폴더 및 확장자를 지정하여 삭제 예외 처리
* 삭제된 파일을 백업하여 지정한 기간 동안 보관 후 삭제
* 파일 생성을 실시간 감시하여 문서로 판단된 파일을 삭제
* 백업된 파일 보관 기간 이후 삭제

*목표기능은 Kernel 4.19 버전과 glibc 2.8 라이브러리의 지원여부에 따라 수정 또는 삭제될 수 있습니다.*

## **전제조건**
본 프로젝트는 각각의 개방형OS를 공통적으로 지원하기 위해 glibc 2.8 라이브러리 기반으로 개발하고 있습니다.

## **라이선스**
본 프로젝트는 LGPL 2.1로 라이선스가 부여되었습니다.

## **참여방법**
나니아이 오픈소스 프로젝트에 참여를 원하시면 info@nannyi.org 로 메일을 보내주십시오. 현재 공개된 소스는 에이전트 모듈이고, 서버와 관리콘솔의 소스를 공개되어 있지 않습니다. 하지만, 프로젝트 참여를 희망하시는 개발자에게 서버와 관리콘솔에 대한 안내를 전달해드릴 수 있으니 info@nannyi.org 로 연락 주십시오.

