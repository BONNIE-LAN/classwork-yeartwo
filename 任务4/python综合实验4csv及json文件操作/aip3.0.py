import requests
import json
import csv
headers = {
    'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Mobile Safari/537.36',
    'Referer': 'http://fundf10.eastmoney.com/jjjz_160706.html'
}
rows=[]
page_count=0
def get_html(url):
    #只处理前10页
    global page_count
    if page_count>=10:
        return
    page_count+=1
    html = requests.get(url,headers=headers)
    html_text= html.text
    print(html_text)
    start = html_text.find('{"Data":{"LSJZList"')
    json_data = json.loads(html_text[start:-1])
    netvalues = json_data['Data']['LSJZList']
    for data in netvalues:
        fsrq = data['FSRQ']
        dwjz = data['DWJZ']
        #新增：累计净值和净值增长率
        ljjz=data['LJJZ']
        jzzz=data['JZZZL']
        print(fsrq,dwjz,ljjz,jzzz)
        rows.append([fsrq,dwjz,ljjz,jzzz])
   

if __name__ == '__main__':
    for i in range(1,201):
        url = 'http://api.fund.eastmoney.com/f10/lsjz?' \
              'callback=jQuery183015088915834593553_1586246635664&' \
              'fundCode=160706&pageIndex={}&pageSize=20&' \
              'startDate=&endDate=&_=1586246635678'.format(i)
        print('当前输出地{}页'.format(i))
        get_html(url)
#把结果写入csv文件中
with open("fund.csv","w",newline="",encoding="utf-8") as f:
    writer=csv.writer(f)
    writer.writerow(['FSRQ','DWJZ','LJJZ','JZZZL'])
    writer.writerows(rows)