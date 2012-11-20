using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Windows.Forms;

namespace WebCrawler
{
    class Page
    {
        private string url;
        private string content;
        public List<Link> links = new List<Link>();

        public Page(string input)
        {
            url = input;
            getPageContent();
        }

        public string getUrl()
        {
            return url;
        }
        public List<Link> getLinks()
        {
            return links; 
        }

        public void getPageContent()
        {
            //MessageBox.Show(url);
            WebRequest request = WebRequest.Create(url);
            WebResponse responce = request.GetResponse();
            Stream data = responce.GetResponseStream();
            StreamReader read = new StreamReader(data);
            content = read.ReadToEnd();
            responce.Close();
            data.Close();
            read.Close();
            request.Abort();
            // end of request
            int start = 0;
            int end;
            while (true)
            {
                start = content.IndexOf("a href=", start);
                if (start == -1) return;
                start += 7;
                if (content[start] == '"')
                {
                    start++;
                    end = content.IndexOf('"', start);
                }
                else
                {
                    int altend = content.IndexOf(' ', start);
                    end = content.IndexOf('>', start);
                    if ((altend != -1) && (altend < end)) end = altend;
                }
                string bufferurl = "";
                for (int i = start; i < end; i++) bufferurl += content[i];
                //MessageBox.Show(bufferurl);
                links.Add(new Link(bufferurl));
                start = end+1;
            }
        }
    }
}
