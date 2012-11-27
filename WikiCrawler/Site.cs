using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
//debug using:
using System.Windows.Forms;

namespace WikiCrawler
{
    class Site
    {
        private int maxpages;
        private string url;
        public string domain;
        public List<Page> pages = new List<Page>();

        public Site(string input, int maxp)
        {
            maxpages = maxp;
            if ((input.IndexOf("http://") == -1) && (input.IndexOf("https://") == -1))
            {
                if (input[0] != '/') input=input.Insert(0, "/");
                input = input.Insert(0, "http:/");
            }
            url = input;
            domain = "";
            for (int charcount = 0; charcount < url.IndexOf('/', 10); charcount++)
            {
                domain += url[charcount];
            }
            lurk();
        }

        private void lurk()
        {
            addpage(url, 0, null);
            for (int stagec = 0; stagec < pages.Count; stagec++)
            {
                for (int linkc = 0; linkc < pages[stagec].links.Count; linkc++)
                {
                    string clink = pages[stagec].links[linkc].url;
                    if ((clink[0] == '/') || (clink.IndexOf(domain) != -1))
                    {
                        if (pages[stagec].depth < maxpages)
                        {
                            addpage(clink, pages[stagec].depth+1, pages[stagec]);
                            for (int lc = 0; lc < pages[pages.Count-1].links.Count; lc++)
                            {
                                if (pages[pages.Count - 1].links[lc].url.Insert(0, domain) == url)
                                {
                                    MessageBox.Show("Match found at depth[" + pages[pages.Count - 1].depth + "]\r\nPage:" + pages[pages.Count - 1].url);
                                    string display = "Depth[" + pages[pages.Count - 1].depth + "] " + pages[pages.Count - 1].url;
                                    Page currpage = pages[pages.Count - 1].motherpage;
                                    while (currpage!=null)
                                    {
                                        display += "\r\nDepth[" + currpage.depth + "] " + currpage.url;
                                        currpage = currpage.motherpage;
                                    }
                                    MessageBox.Show(display);
                                    return;
                                }
                            }
                        }
                    }
                    else continue; // exiting wiki, no interest
                }
            }
        }

        public void addpage(string input, int pagedepth, Page previous)
        {
            if (input == "==Error occured==") return;
            if ((input.IndexOf("http://") == -1) && (input.IndexOf("https://") == -1))
            {
                if (input[0] != '/') input=input.Insert(0, "/");
                input=input.Insert(0, domain);
            }
            pages.Add(new Page(input, pagedepth, previous));
        }

    }
}
