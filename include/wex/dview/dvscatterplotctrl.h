#ifndef __DVScatterplotCtrl_h
#define __DVScatterplotCtrl_h

#include <wx/panel.h>
#include <vector>

class wxPLPlotCtrl;
class wxDVSelectionListCtrl;
class wxDVTimeSeriesDataSet;

class wxDVScatterPlotCtrl : public wxPanel
{
public:
	wxDVScatterPlotCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = "panel");
	
	void AddDataSet(wxDVTimeSeriesDataSet* d, const wxString& group, bool update_ui);
	void RemoveDataSet(wxDVTimeSeriesDataSet* d);
	void RemoveAllDataSets();

	wxDVSelectionListCtrl* GetScatterSelectionList();
	void SetXSelectedName(const wxString& name);
	void SetYSelectedNames(const wxString& names);
	void SelectXDataAtIndex(int index);
	void SelectYDataAtIndex(int index);

	//EVENT HANDLERS
	void OnChannelSelection( wxCommandEvent & );

private:
	std::vector<wxDVTimeSeriesDataSet*> m_dataSets;

	wxDVSelectionListCtrl *m_dataSelectionList;
	int m_xDataIndex;
	std::vector<int> m_yDataIndices;

	wxPLPlotCtrl *m_plotSurface;

	void SetXAxisChannel(int index);
	void AddYAxisChannel(int index);
	void RemoveYAxisChannel(int index);
	void UpdatePlotWithChannelSelections();
	void RefreshDisabledCheckBoxes();


	DECLARE_EVENT_TABLE()
};

#endif
