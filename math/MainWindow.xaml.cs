using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace math
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        private List<string> ex =new List<string>();

        public MainWindow()
        {
            InitializeComponent();
        }

        public class Dllfun
        {
            [DllImport("../../../Debug/math_dll.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr GetExercises(int Operator, int isDecimal,int isBrackets, int Maxnum);
            
        }

        private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            
        }

        private void btbegin_Click(object sender, RoutedEventArgs e)
        {
            listView.Items.Clear();
            int Operator = 0;
            if(checkBox.IsChecked == true)
            {
                Operator = 1000;
            }
            if (checkBox1.IsChecked == true)
            {
                Operator = Operator + 100 ;
            }
            if (checkBox2.IsChecked == true)
            {
                Operator = Operator + 10;
            }
            if (checkBox3.IsChecked == true)
            {
                Operator = Operator + 1;
            }
            if (Operator == 0)
            {
                MessageBox.Show("请至少选择一种运算操作符", "提示", MessageBoxButton.OK, MessageBoxImage.None);
            }
            else
            {
                ex.Clear();   
                for (int i = 0; i < (int)silder1.Value; i++)
                {                                                                   // 
                    string str = Marshal.PtrToStringAnsi(Dllfun.GetExercises(Operator, Convert.ToInt32(checkBox4.IsChecked), 1, (int)silder.Value));
                    ex.Add(str);
                    listView.Items.Add(new { Num = (i + 1).ToString(), Name = str, });
                }
            }
            
        }

        private void silder_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
           
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (ex.Count() == 0)
            {
                MessageBox.Show("请先生成题目", "提示", MessageBoxButton.OK, MessageBoxImage.None);
            }
            else
            {
                string Nameoftxt = DateTime.Now.ToString("yyyyMMddHHmm");
                Directory.CreateDirectory("../../../../数学题文件夹");
                string path = @"../../../../数学题文件夹/" + Nameoftxt + ".txt";
                StreamWriter streamWriter = new StreamWriter(path);

                int index = 1;
                streamWriter.WriteLine("题目编号              题目");
                foreach (string str in ex)
                {
                    streamWriter.WriteLine((index++).ToString() + "                  " + str);
                }
                //刷新缓存
                streamWriter.Flush();
                //关闭流
                streamWriter.Close();
                MessageBox.Show("题目已保存在文件中", "提示", MessageBoxButton.OK, MessageBoxImage.None);
            }
        }
    }

}
