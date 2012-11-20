using System;

using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
namespace WebCrawler
{
    class Site
    {
        private string url;
        private int type;
        public List<Page> pages = new List<Page>();
        private static string domain;

        private void deeper(string link)
        {
            pages.Add(new Page(link));
            int stage = pages.Count - 1;
            for (int i = 0; i < pages[stage].links.Count; i++)
            {
                string buffer = pages[stage].links[i].url;
                if (buffer.IndexOf(domain) != -1)
                {
                    //MessageBox.Show(i + " " + buffer);
                    //continue;
                    pages.Add(new Page(buffer));
                }
                else if (buffer[0] == '/')
                {
                    buffer = buffer.Insert(0, "http://" + domain);
                    //MessageBox.Show(i + " " + buffer);
                    //continue;
                    pages.Add(new Page(buffer));
                }
            }
        }

        private void spage(string link)
        {
            pages.Add(new Page(link));
        }

        public Site(string inputurl, int meth)
        {
            type = meth;
            url = inputurl;
            if (url.IndexOf("http") == -1)
            {
                url=url.Insert(0,"http://");
            }
            int dstart = url.IndexOf("://");
            dstart += 3;
            int dend = url.IndexOf("/" , dstart);
            if (dend == -1) dend = url.Length;
            domain="";
            for(int i=dstart; i<dend; i++) domain+=url[i];
            if (type == 0) deeper(url);
            else if (type == 1) spage(url);
        }
        
    }
}
