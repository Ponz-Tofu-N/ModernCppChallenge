#include "image_pdf.h"

// std::vector<std::string>

int main(int argc, char const *argv[]) {
  const char *root = "/home/haraponz/ModernCppChallengePractice/078/res";

  ImagePrinter printer{root};
  printer.PrintAllImage();

  // PDFWriter writer;
  // EStatusCode status;
  // status = writer.StartPDF("BasicJPGImagesTest.pdf", ePDFVersion13);

  // PDFPage *page = new PDFPage();
  // page->SetMediaBox(PDFRectangle(0, 0, WIDTH, HEIGHT));

  // PageContentContext *cxt = writer.StartPageContentContext(page);
  // std::vector<Path> paths;
  // for (auto &&f : std::filesystem::directory_iterator{root}) {
  //   if (!f.is_regular_file()) continue;

  //   const auto &p = f.path();
  //   if (p.extension() != ".jpg") continue;

  //   paths.emplace_back(p);
  // }

  // DoubleAndDoublePair jpgDimensions = writer.GetImageDimensions(paths[0]);
  // std::cout << jpgDimensions.first << " " << jpgDimensions.second << "\n";

  // const auto &jpg_w = jpgDimensions.first;
  // const auto &jpg_h = jpgDimensions.second;

  // AbstractContentContext::ImageOptions opt;
  // opt.transformationMethod = AbstractContentContext::eMatrix;
  // opt.matrix[0] = opt.matrix[3] = 0.25;
  // cxt->DrawImage(LEFT, TOP - jpg_h, paths[0].generic_string());
  // writer.EndPageContentContext(cxt);
  // writer.WritePageAndRelease(page);

  // writer.EndPDF();
  return 0;
}
