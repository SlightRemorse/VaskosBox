using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;
using System.Text.RegularExpressions;
//debug using:
using System.Windows.Forms;

namespace WikiCrawler
{
    class Page
    {
        public string url;
        public int depth;
        private string content;
        public List<Link> links = new List<Link>();

        public Page(string input, int pagedepth)
        {
            url = input;
            depth = pagedepth;
            try
            {
                WebRequest request = WebRequest.Create(url);
                WebResponse responce = request.GetResponse();
                Stream data = responce.GetResponseStream();
                StreamReader read = new StreamReader(data);
                content = read.ReadToEnd();
                responce.Close();
                data.Close();
                read.Close();
                request.Abort();
            }
            catch 
            {
                links.Add(new Link("==Error occured=="));
                return;
            }
            search(content);
        }

        private void search(string input)
        {
            foreach (Match rough in Regex.Matches(input, "(<a.*?href.*?>)"))
            {
                string buffer = Regex.Replace(rough.Value, "^<a.*?href[ ]?=[ ]?[\"]?[ ]?", String.Empty);
                if (buffer[0] == '#') continue; // # is not a link to a new site
                buffer = Regex.Replace(buffer, "[\"]?( .*|>)", String.Empty);
                if(url.IndexOf(buffer)==-1) links.Add(new Link(buffer));
            }
            
        }
    }
}
