vm = open("./trace_result.txt", 'r')
vpns = open("./vpn.txt", "w")

for v in vm:
    if(v[0]!="="):
        # 16진수 문자열을 10진수로 변환
        decimal_num = int(v[3:11], 16)
        # 10진수 값에서 하위 12비트를 제거 (AND연산자 이용)
        mask = 0xfffff000
        masked = decimal_num & mask
        # 12비트만큼 오른쪽으로 shift해 상위 20비트 값을 문자열로 반환
        result_vpn = str(masked >> 12)
        # 결과를 write
        vpns.write(result_vpn + "\n")

vm.close()
vpns.close()

