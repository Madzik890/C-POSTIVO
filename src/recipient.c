#include "recipient.h"
#include <stdio.h>
#include <string.h>

char * assingSource(const int answer);
char * assingString(const char * consoleWrite);

void createRecipient(struct ns1__Recipient * recipient)
{
  struct ns1__Recipient m_recipient;
  int l_sourceAnswer = 0;
  printf("1)Group\n");
  printf("2)Book \n");
  printf("3)Inline \n");
  printf("Enter the source type:");
  scanf("%d", &l_sourceAnswer);//waits for user input
  m_recipient.source = assingSource(l_sourceAnswer);

  /// <assing the id>
  int i_id;
  if(l_sourceAnswer != 3)
  {
    printf("Enter the recipient's id :");
    scanf("%d", &i_id);//waits for user input
    m_recipient.id = malloc(sizeof(char) * 20);
    m_recipient.id = (int*)i_id;
  }
  /// </assing the id>

  if(l_sourceAnswer == 3)
  {
  /// <assing the recipient name>
    m_recipient.recipient_USCOREname = assingString("Enter the recipient's name:");
  /// </assing the recipient name>

  /// <assing the post code>
    m_recipient.recipient_USCOREpost_USCOREcode = assingString("Enter the post code:");
  /// </assing the post code>

  /// <assing the city>
    m_recipient.recipient_USCOREcity = assingString("Enter the city:");
  /// </assing the city>

  /// <assing the address prefix>
    m_recipient.recipient_USCOREaddress_USCOREprefix = assingString("Enter the adress prefix:");
  /// </assing the address prefix>

  /// <assing the address>
    m_recipient.recipient_USCOREaddress = assingString("Enter the address:");
  /// </assing the address>

  /// <assing the home number>
    m_recipient.recipient_USCOREhome_USCOREnumber = assingString("Enter the home number:");
  /// </assing the home number>

  /// <assing the float number>
    m_recipient.recipient_USCOREflat_USCOREnumber = assingString("Enter the flat number:");
  /// <assing the float number>

  m_recipient.recipient_USCOREcountry = NULL;
  m_recipient.recipient_USCOREfax_USCOREnumber = NULL;
  }
  (*recipient) = m_recipient;
}

char * assingSource(const int answer)
{
  char * s_string = malloc(sizeof(char) * 20);
  switch (answer)
  {
    case 1:
      strcpy(s_string, "inline");
    break;

    case 2:
      strcpy(s_string,"group");
    break;

    case 3:
      strcpy(s_string,"book");
    break;

    default:
      strcpy(s_string, "inline");
  }

  return s_string;
}

char * assingString(const char * consoleWrite)
{
    char * s_string = malloc(sizeof(char) * 100);
    printf("%s",consoleWrite);
    scanf("%s", s_string);//waits for user input

    return s_string;
}
