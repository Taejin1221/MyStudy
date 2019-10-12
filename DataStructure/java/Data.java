package java;

/**
 * TreeNode에 쓰일 Data 클래스의 추상클래스.
 * @author Jin
 *
 */

abstract public class Data {
	protected int time;
	
	/** time 변수를 1로 초기화 */
	protected Data() {
		this.time = 1;
	}
	
	/**
	 * Data의 순서 비교 함수.
	 * this.data와 data비교.
	 * @param data 비교할 대상 data
	 * @return -1(작을시), 0(같을시), 1(클시)
	 */
	abstract protected int compare(Data data);
	
	/** time 증가 함수 */
	abstract protected void IncrementTime();
	/** time 감소 함수 */
	abstract protected void DecrementTime();
}