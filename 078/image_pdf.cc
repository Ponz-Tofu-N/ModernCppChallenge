#include "image_pdf.h"

ImagePrinter::ImagePrinter(std::string const &dirpath) {
  targetfile_ = GetFilePaths(dirpath);
  status_ = writer_.StartPDF("BasicJPGImagesTest.pdf", ePDFVersion13);
}

ImagePrinter::~ImagePrinter() {
  // writer.EndPageContentContext(cxt);
  // writer.WritePageAndRelease(page);

  writer_.EndPDF();
}

std::vector<Path> ImagePrinter::GetFilePaths(Path const &path) {
  std::vector<Path> paths;
  for (auto &&f : std::filesystem::directory_iterator(path)) {
    if (!f.is_regular_file()) continue;

    const auto &p = f.path();
    if (p.extension() != ".jpg") continue;

    paths.emplace_back(p);
  }

  return paths;
}
// void ImagePrinter::CreatePdf() {}

void ImagePrinter::PrintImageAt(int x, int y, Path const &path) {}

size_t ImagePrinter::GetImageHeight(Path const &path) {
  PDFWriter w;
  DoubleAndDoublePair jpgDimensions =
      w.GetImageDimensions(path.generic_string());
  return jpgDimensions.second;
}

void ImagePrinter::PrintAllImage() {
  PDFPage *page = nullptr;
  PageContentContext *cxt = nullptr;

  int rest_of_height = TOP;
  // int current_pos = TOP;
  for (auto &&image_path : targetfile_) {
    // PrintImageAt(10, rest_of_space, path);
    int h = GetImageHeight(image_path);
    if (rest_of_height - h < 0) {
      writer_.EndPageContentContext(cxt);
      writer_.WritePageAndRelease(page);
      page = nullptr;

      rest_of_height = TOP;
    }

    if (page == nullptr) {
      // CreatePdf();
      page = new PDFPage();
      page->SetMediaBox(PDFRectangle(0, 0, WIDTH, HEIGHT));
      cxt = writer_.StartPageContentContext(page);
    }

    cxt->DrawImage(LEFT, rest_of_height - h, image_path.generic_string());
    rest_of_height -= h;
  }

  writer_.EndPageContentContext(cxt);
  writer_.WritePageAndRelease(page);

  // writer_.EndPDF();
}
