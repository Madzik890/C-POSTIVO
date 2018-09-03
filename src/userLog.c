#include "userLog.h"
#include <stdio.h>
#include <string.h>//strcpy

/// <summary>
/// </summary>
/// <return> User object which login and password. </return>
struct userLog getUserLog()
{
  struct userLog m_user;
  char * s_login = malloc(sizeof(char) * 255);//allocates a 256 place for login
  m_user.s_login = malloc(sizeof(char) * 256);
  char * s_password = malloc(sizeof(char) * 255);//allocates a 256 place for password
  m_user.s_password = malloc(sizeof(char) * 256);


  printf("Login:");
  scanf("%s", s_login);//waits for user input
  strcpy(m_user.s_login, s_login);

  printf("Password:");
  scanf("%s", s_password);//waits for user input
  strcpy(m_user.s_password, s_password);

  free(s_login);//release a memory from the login
  free(s_password);//relase a memory frome the password

  return m_user;//return a user data
}

void freeUserLog(struct userLog * user)
{
  free(user->s_login);
  free(user->s_password);
}
