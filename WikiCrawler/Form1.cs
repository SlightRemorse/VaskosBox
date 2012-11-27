using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WikiCrawler
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void wikibutton_Click(object sender, EventArgs e)
        {
            try
            {
                Site worksite = new Site(inputbox.Text, Convert.ToInt32(depthbox.Text));
                outputbox.Text = "";
                for (int pagecount = 0; pagecount < worksite.pages.Count; pagecount++)
                {
                    outputbox.AppendText("\r\n\r\nDepth[" + worksite.pages[pagecount].depth.ToString() + "]:" + worksite.pages[pagecount].url + "\r\n");
                    for (int linkcount = 0; linkcount < worksite.pages[pagecount].links.Count; linkcount++)
                    {
                        if ((worksite.pages[pagecount].links[linkcount].url.IndexOf(worksite.domain) == -1) && (worksite.pages[pagecount].links[linkcount].url.IndexOf("http") != -1))
                        {
                            outputbox.AppendText("%WIKI EXIT% ");
                        }
                        outputbox.AppendText(worksite.pages[pagecount].links[linkcount].url + "\r\n");
                    }
                }
                MessageBox.Show("Finished.");
            }
            catch
            {
                MessageBox.Show("Please enter max Depth");
            }
        }
    }
}
