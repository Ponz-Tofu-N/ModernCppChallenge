#ifndef IMAGE_PDF_HH
#define IMAGE_PDF_HH

#include <PDFWriter/PDFPage.h>
#include <PDFWriter/PDFWriter.h>
#include <PDFWriter/PageContentContext.h>

#include <filesystem>
#include <iostream>
#include <vector>

using Path = std::filesystem::path;

constexpr uint16_t HEIGHT = 842;
constexpr uint16_t WIDTH = 595;
constexpr uint16_t TOP = 822;
constexpr uint16_t BOTTOM = 20;
constexpr uint16_t LEFT = 20;
constexpr uint16_t RIGHT = 575;

class ImagePrinter {
 public:
  explicit ImagePrinter(std::string const &dirpath);
  ~ImagePrinter();

  void PrintAllImage();
  // void CreatePdf();
  void PrintImageAt(int x, int y, Path const &path);
  std::vector<Path> GetFilePaths(Path const &path);

  static size_t GetImageHeight(Path const &path);

 private:
  PDFWriter writer_;
  EStatusCode status_;
  std::vector<Path> targetfile_;
};

#endif