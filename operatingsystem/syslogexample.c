#include <stdio.h>
#include <syslog.h>

int main() {
    openlog("MyApp", LOG_PID | LOG_CONS, LOG_USER);

    // 로그 작성
    syslog(LOG_INFO, "This is an informational message.");
    syslog(LOG_WARNING, "This is a warning message.");
    syslog(LOG_ERR, "This is an error message.");

    // syslog 종료
    closelog();

    return 0;
}
