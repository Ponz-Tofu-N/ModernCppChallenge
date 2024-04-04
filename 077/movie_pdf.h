#include <iomanip>
#include <iostream>
#include <string>

#include "movie.h"

#include <PDFWriter/PDFPage.h>
#include <PDFWriter/PDFUsedFont.h>
#include <PDFWriter/PDFWriter.h>
#include <PDFWriter/PageContentContext.h>

constexpr uint16_t HEIGHT = 842;
constexpr uint16_t WIDTH = 595;
constexpr uint16_t TOP = 770;
constexpr uint16_t BOTTOM = 10;
constexpr uint16_t LEFT = 20;
constexpr uint16_t RIGHT = 575;

void print_movie_list(const std::string &filepath, const movie_list &movies) {

  PDFWriter pdfWriter;
  pdfWriter.StartPDF(filepath, ePDFVersion13);
  PDFPage *page = new PDFPage();
  page->SetMediaBox(PDFRectangle(0, 0, WIDTH, HEIGHT));

  PageContentContext *cxt = pdfWriter.StartPageContentContext(page);

  PDFUsedFont *font = pdfWriter.GetFontForFile(
      "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");

  AbstractContentContext::TextOptions textOptions(
      font, 20, AbstractContentContext::eGray, 0);
  cxt->WriteText(LEFT, TOP + 15, "Movie List", textOptions);

  DoubleAndDoublePairList path;
  path.push_back(DoubleAndDoublePair{LEFT, TOP});
  path.push_back(DoubleAndDoublePair{RIGHT, TOP});

  AbstractContentContext::GraphicOptions pathStrokeOptions(
      AbstractContentContext::eStroke, AbstractContentContext::eRGB,
      AbstractContentContext::ColorValueForName("Black"), 4);
  cxt->DrawPath(path, pathStrokeOptions);

  constexpr auto height = HEIGHT / 25;

  textOptions.fontSize = 12;
  for (auto i = movies.begin(); i != movies.end(); i++) {
    int index = i - movies.begin() + 1;

    std::stringstream ss;
    ss << i->title << " (" << i->release_year << ")";
    cxt->WriteText(LEFT, TOP - height * index, ss.str(), textOptions);

    ss.str("");
    ss << std::to_string(i->length / 60) << ":"
       << std::to_string(i->length % 60);
    auto text_meta = font->CalculateTextDimensions(ss.str(), 20);
    cxt->WriteText(RIGHT - text_meta.width, TOP - height * index, ss.str(),
                   textOptions);
  }

  pdfWriter.EndPageContentContext(cxt);

  pdfWriter.WritePageAndRelease(page);
  pdfWriter.EndPDF();
}
