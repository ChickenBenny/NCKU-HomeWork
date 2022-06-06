#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
Location answer;
Location *parse_url(char *url)
{
    int n = strlen(url);
    char * index = url, *tmp;
    *(url + (n - 1)) = '\0';
    answer.protocol = url + n -1, answer.pathname = url + n - 1, answer.hash = url + n -1, answer.search = url + n -1, answer.host = url + n -1;
    answer.port = 0;
    if (strstr(url, "://")){
        answer.protocol = index;
        index = strstr(url, "://");
        * index = '\0';
        index += 3;
    }
    if (strstr(index, ":")){
        answer.host = index;
        index = strstr(index, ":");
        * index = '\0';
        index += 1;
        if (strstr(index, "/")){
            tmp = index;
            index = strstr(index, "/");
            *index = '\0';
            answer.port = atoi(tmp);
        }
        else {
            if (strcmp(answer.protocol, "https") == 0)
                answer.port = 443;
        }
        index += 1;
    }
    else if (strstr(index, "/")){
        answer.host = index;
        index = strstr(index, "/");
        *index = '\0';
        index += 1;
        if (strcmp(answer.protocol, "https") == 0)
            answer.port = 443;
    }
    else{
        answer.host = index;
        if (strcmp(answer.protocol, "https") == 0)
            answer.port = 443;
        return &answer;
    }
    if (strstr(index, "?")){
        answer.pathname = index;
        index = strstr(index, "?");
        *index = '\0';
        index += 1;
    }
    else {
        answer.pathname = index;
        return &answer;
    }
    if (strstr(index, "#")){
        answer.search = index;
        index = strstr(index, "#");
        *index = '\0';
        index += 1;
        answer.hash = index;
        return &answer;
    }
    else {
        return &answer;
    }
}
