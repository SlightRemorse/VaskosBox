namespace WikiCrawler
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.inputbox = new System.Windows.Forms.TextBox();
            this.wikibutton = new System.Windows.Forms.Button();
            this.outputbox = new System.Windows.Forms.TextBox();
            this.depthbox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // inputbox
            // 
            this.inputbox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.inputbox.Location = new System.Drawing.Point(12, 12);
            this.inputbox.Name = "inputbox";
            this.inputbox.Size = new System.Drawing.Size(568, 20);
            this.inputbox.TabIndex = 0;
            // 
            // wikibutton
            // 
            this.wikibutton.Location = new System.Drawing.Point(13, 39);
            this.wikibutton.Name = "wikibutton";
            this.wikibutton.Size = new System.Drawing.Size(75, 23);
            this.wikibutton.TabIndex = 1;
            this.wikibutton.Text = "Wiki me!";
            this.wikibutton.UseVisualStyleBackColor = true;
            this.wikibutton.Click += new System.EventHandler(this.wikibutton_Click);
            // 
            // outputbox
            // 
            this.outputbox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.outputbox.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.outputbox.ForeColor = System.Drawing.SystemColors.ControlText;
            this.outputbox.Location = new System.Drawing.Point(13, 69);
            this.outputbox.Multiline = true;
            this.outputbox.Name = "outputbox";
            this.outputbox.ReadOnly = true;
            this.outputbox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.outputbox.Size = new System.Drawing.Size(567, 185);
            this.outputbox.TabIndex = 2;
            // 
            // depthbox
            // 
            this.depthbox.Location = new System.Drawing.Point(94, 41);
            this.depthbox.Name = "depthbox";
            this.depthbox.Size = new System.Drawing.Size(61, 20);
            this.depthbox.TabIndex = 3;
            this.depthbox.Text = "MaxDepth";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(592, 266);
            this.Controls.Add(this.depthbox);
            this.Controls.Add(this.outputbox);
            this.Controls.Add(this.wikibutton);
            this.Controls.Add(this.inputbox);
            this.Name = "Form1";
            this.Text = "Wiki Crawler";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox inputbox;
        private System.Windows.Forms.Button wikibutton;
        private System.Windows.Forms.TextBox outputbox;
        private System.Windows.Forms.TextBox depthbox;
    }
}

