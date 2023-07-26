#include <stdio.h>
#include <syslog.h>

int main() {

    // "MyApp": 로그에 표시될 프로그램 이름은 MyApp
    // LOG_PID | LOG_CONS: 로그 메세지에 PID 명시, 로그 메세지를 콘솔에 출력
    // LOG_USER: 사용자가 발생시킨 로그
    openlog("MyApp", LOG_PID | LOG_CONS, LOG_USER);

    // 로그 작성
    syslog(LOG_INFO, "This is an informational message.");
    syslog(LOG_WARNING, "This is a warning message.");
    syslog(LOG_ERR, "This is an error message.");

    // syslog 종료
    closelog();

    return 0;
}
