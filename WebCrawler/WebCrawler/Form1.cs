using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WebCrawler
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<Link> bufferlist;
            resultbox.Clear();
            Site workurl = new Site(starturl.Text, 0);
            for (int a = 0; a < workurl.pages.Count; a++)
            {
                resultbox.AppendText("=======" + workurl.pages[a].getUrl() + "=======\r\n");
                bufferlist = workurl.pages[a].getLinks();
                for (int i = 0; i < bufferlist.Count(); i++) resultbox.AppendText(bufferlist[i].url + "\r\n");
            }
            MessageBox.Show("Done.");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            List<Link> bufferlist;
            resultbox.Clear();
            Site workurl = new Site(starturl.Text, 1);
            for (int a = 0; a < workurl.pages.Count; a++)
            {
                resultbox.AppendText("=======" + workurl.pages[a].getUrl() + "=======\r\n");
                bufferlist = workurl.pages[a].getLinks();
                for (int i = 0; i < bufferlist.Count(); i++) resultbox.AppendText(bufferlist[i].url + "\r\n");
            }
            MessageBox.Show("Done.");   
        }
    }
}
