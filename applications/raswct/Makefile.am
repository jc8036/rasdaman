SRC = toolkit
BIN = bin
LIB = lib
CP = cp -r
RM = rm -rf
MKDIR = mkdir
INSTALL_DIR = $(DESTDIR)$(datadir)/rasdaman/raswct

all: css libs src
	@cat $(BIN)/raswct_lib.js $(BIN)/raswct_src.js > $(BIN)/raswct.js
	@echo "Build Process sucessfully. You can now install the toolkit by running $ make install"

css:
	@cat $(LIB)/jqueryui/css/ui-lightness/jquery-ui-1.8.16.custom.css $(LIB)/gritter/jquery.gritter.css $(LIB)/charts/jquery.jqplot.css $(LIB)/openlayers/style.css > $(BIN)/raswct.css


libs:
	@cat $(LIB)/jqueryui/js/jquery-1.6.2.min.js $(LIB)/jqueryui/js/jquery-ui-1.8.16.custom.min.js $(LIB)/gritter/gritter.js $(LIB)/jsclass/min/loader-browser.js $(LIB)/jsclass/min/core.js $(LIB)/jsclass/min/deferrable.js $(LIB)/openlayers/OpenLayers.js $(LIB)/charts/jquery.jqplot.min.js $(LIB)/charts/plugins/jqplot.canvasAxisLabelRenderer.min.js $(LIB)/charts/plugins/jqplot.canvasAxisTickRenderer.min.js $(LIB)/charts/plugins/jqplot.canvasOverlay.js $(LIB)/charts/plugins/jqplot.categoryAxisRenderer.min.js $(LIB)/charts/plugins/jqplot.canvasTextRenderer.min.js $(LIB)/charts/plugins/jqplot.cursor.min.js $(LIB)/charts/plugins/jqplot.dateAxisRenderer.min.js $(LIB)/charts/plugins/jqplot.dragable.min.js $(LIB)/charts/plugins/jqplot.enhancedLegendRenderer.min.js $(LIB)/charts/plugins/jqplot.highlighter.min.js $(LIB)/charts/plugins/jqplot.logAxisRenderer.min.js $(LIB)/charts/plugins/jqplot.meterGaugeRenderer.min.js $(LIB)/charts/plugins/jqplot.pieRenderer.min.js $(LIB)/charts/plugins/jqplot.pointLabels.min.js $(LIB)/gauges/raphael.js $(LIB)/gauges/wso2vis.ctrls.js > $(BIN)/raswct_lib.js


src:
	@cat $(SRC)/Init.js $(SRC)/Util.js $(SRC)/Query/BaseQuery.js $(SRC)/Query/SelectQuery.js $(SRC)/Query/UrlQuery.js $(SRC)/Query/QueryExecutor.js $(SRC)/Widgets/BaseWidget.js $(SRC)/Widgets/InputWidget.js $(SRC)/Widgets/OutputWidget.js $(SRC)/Widgets/BaseChart.js $(SRC)/Widgets/LinearDiagram.js $(SRC)/Widgets/AreaDiagram.js $(SRC)/Widgets/ScatterDiagram.js $(SRC)/Widgets/LayerWidget.js $(SRC)/Widgets/MapWidget.js $(SRC)/Widgets/TextWidget.js $(SRC)/Widgets/SliderWidget.js $(SRC)/Widgets/DiscreteSliderWidget.js $(SRC)/Widgets/ImageSlicesWidget.js $(SRC)/Widgets/Knob.js $(SRC)/Widgets/LedDisplay.js $(SRC)/Widgets/Gauge.js > $(BIN)/raswct_src.js

install:
	@$(MKDIR) -p $(INSTALL_DIR)
	@$(CP) $(BIN)/* $(INSTALL_DIR)
	@echo "The rasdaman web client toolkit has been installed. You can start using it by including raswct.js and raswct.css in your html file"

uninstall:
	@$(RM) $(INSTALL_DIR)
	@echo "The rasdaman web client toolkit was uninstalled"

clean:
	@$(RM) $(BIN)/raswct.js $(BIN)/raswct_src.js $(BIN)/raswct_lib.js $(BIN)/raswct.css
	@echo "The compiled files were removed"

EXTRA_DIST = *
