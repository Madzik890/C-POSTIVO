/*
 * Postivo is website which you must upload files.
 * This section prepare files to send.
 */
#include "documentFile.h"
#include "base64/base64.h"
#include <stdio.h>
#include <string.h>//strlen

void inputFilePath(char ** filePath, char ** fileTitle)
{
  char * s_filePath = malloc(sizeof(char) * 255);
  char * s_fileTitle = malloc(sizeof(char) * 255);
  printf("Enter the file path:");
  scanf("%s", s_filePath);
  printf("Enter the file title:");
  scanf("%s", s_fileTitle);

  (*filePath) = s_filePath;
  (*fileTitle) = s_fileTitle;
}

/// <summary>
/// Opens the document file and loads it to the struct which stores buffer with the file.
/// Next, document is sends to the website.
/// </summary>
/// <param name = "fileLocation"> Contain the location to file. <param>
/// <param name = "document"> Struct which have variable to contain the file and it title. <param>
void loadDocumentFile(const char * fileLocation, const char * fileTitle, struct ns1__DocumentFile * document)
{
  FILE * m_file;
  struct ns1__DocumentFile m_document;
  long l_lenght;//lenght in file

  m_document.file_USCOREname = fileTitle;//title

  m_file = fopen(fileLocation,"rb");
  if(m_file)
  {
    fseek (m_file, 0, SEEK_END);//check end of file
    l_lenght = ftell(m_file);//assign this variable lenght of the file
    fseek(m_file, 0, SEEK_SET);

    m_document.file_USCOREstream = malloc(sizeof(char) * l_lenght);
    fread(m_document.file_USCOREstream, sizeof(char), l_lenght, m_file);//read binary in to the file
    char * s_encodedStream = base64encode(m_document.file_USCOREstream, l_lenght);//encode the file
    free(m_document.file_USCOREstream);

    m_document.file_USCOREstream = malloc(sizeof(char) * strlen(s_encodedStream) + 1);//allocating the place in the memory
    m_document.file_USCOREstream = s_encodedStream;

    fclose(m_file);//close the file
  }
  (*document) = m_document;
}

/// <summary>
/// Releases the memory after sent this file.
/// </summary>
void freeDocumentFile(struct ns1__DocumentFile * document)
{
   free(document->file_USCOREstream);//release the file buffor
}
